#!/bin/sh
#
# $FreeBSD$
#
# This script is used by release/Makefile to build the (optional) ISO images
# for a FreeBSD release.  It is considered architecture dependent since each
# platform has a slightly unique way of making bootable CDs. This script is
# also allowed to generate any number of images since that is more of
# publishing decision than anything else.
#
# Usage:
#
# mkisoimages.sh [-b] image-label image-name base-bits-dir [extra-bits-dir]
#
# Where -b is passed if the ISO image should be made "bootable" by
# whatever standards this architecture supports (may be unsupported),
# image-label is the ISO image label, image-name is the filename of the
# resulting ISO image, base-bits-dir contains the image contents and
# extra-bits-dir, if provided, contains additional files to be merged
# into base-bits-dir as part of making the image.

if [ -z $ETDUMP ]; then
	ETDUMP=etdump
fi

if [ -z $MAKEFS ]; then
	MAKEFS=makefs
fi

if [ -z $MKIMG ]; then
	MKIMG=mkimg
fi

if [ "$1" = "-b" ]; then
	BASEBITSDIR="$4"

	# Make EFI system partition (should be done with makefs in the future)
	dd if=/dev/zero of=efiboot.img bs=4k count=200
	device=`mdconfig -a -t vnode -f efiboot.img`
	newfs_msdos -F 12 -m 0xf8 /dev/$device
	mkdir efi
	mount -t msdosfs /dev/$device efi
	mkdir -p efi/efi/boot
	cp -p "$BASEBITSDIR/boot/loader.efi" efi/efi/boot/bootaa64.efi
	umount efi
	rmdir efi
	mdconfig -d -u $device
	bootable="-o bootimage=i386;efiboot.img -o no-emul-boot -o platformid=efi"

	shift
else
	BASEBITSDIR="$3"
	bootable=""
fi

if [ $# -lt 3 ]; then
	echo "Usage: $0 [-b] image-label image-name base-bits-dir [extra-bits-dir]"
	exit 1
fi

LABEL=`echo "$1" | tr '[:lower:]' '[:upper:]'`; shift
NAME="$1"; shift

publisher="The FreeBSD Project.  https://www.FreeBSD.org/"
echo "/dev/iso9660/$LABEL / cd9660 ro 0 0" > "$BASEBITSDIR/etc/fstab"
$MAKEFS -t cd9660 $bootable -o rockridge -o label="$LABEL" -o publisher="$publisher" "$NAME" "$@"
rm -f "$BASEBITSDIR/etc/fstab"
rm -f ${espfilename}

if [ "$bootable" != "" ]; then
	# Look for the EFI System Partition image we dropped in the ISO image.
	for entry in `$ETDUMP --format shell $NAME`; do
		eval $entry
		# XXX: etdump(8) returns "default" for the initial entry
		if [ "$et_platform" = "default" ]; then
			espstart=`expr $et_lba \* 2048`
			espsize=`expr $et_sectors \* 512`
			espparam="-p efi::$espsize:$espstart"
			break
		fi
	done

	# Create a GPT image containing the EFI partition.
	imgsize=`stat -f %z "$NAME"`
	$MKIMG -s gpt \
	    --capacity $imgsize \
	    $espparam \
	    -o efi.img

	# Drop the GPT into the System Area of the ISO.
	dd if=efi.img of="$NAME" bs=32k count=1 conv=notrunc
	rm -f efi.img
fi
