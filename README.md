ecc_check for xeon e3
=========

Check ECC memory

* Build
sh build.sh

* Output

0: ECC disabled

1: ECC is active in I/O; ECC logic is not active In this case.

2: ECC is disabled in I/O, but ECC logic is enabled.

3: ECC active in both I/O and ECC logic

See ref Page 219 on http://www.intel.com/content/www/us/en/processors/xeon/xeon-e3-1200-family-vol-2-datasheet.html
