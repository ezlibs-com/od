Model: 
	3rd: 3rd-ring-buffer
	lib:
About:
===============================================================================
libs                                function
-------------------------------------------------------------------------------
# 3rd-adns
        异步dns
# 3rd-cares
        异步dns
# 3rd-jerasure
        纠删码
# 3rd-jsoncpp
        json编解码库

# 3rd-srt
        srt通讯库

|No |                               Name |Memo                                       |
|----|------------------------------------:|-------------------------------------------|
| |libcjs                              |cJSON and struct2json实现的cjson解析和构造 |
| |libuniFace                          |调用接口实现 - c                           |
| |libxml2                             |for libs3                                  |
| |libs3                               |libs for s3 cloud storage                  |
| |libcurl                             |zlib, openssl(for gkey), curl library      |
| |libe2fsprogs                        |uuid                                       |
| |libPlatFormTools                    |a                                          |
| |libXML                              |a                                          |
| |libaspweb                           |based go ahead, asp pages                  |
| |libe2fsprogs                        |a                                          |
| |libezConfig                         |a                                          |
| |libezThread                         |a                                          |
| |libezUtilCPP                        |a                                          |
| |libezserial                         |a                                          |
| |libezsip                            |a                                          |
| |libezsocket                         |a                                          |
| |libezutil                           |a                                          |
| |libezwebs                           |mongoose                                   |
| |libfs                               |a                                          |
| |libfs.little.cu                     |a                                          |
| |libgemini                           |a                                          |
| |libjson                             |a                                          |
| |liblua                              |a                                          |
| |libman                              |the library model                          |
| |libppSockets                        |a                                          |
| |libpro                              |a                                          |
| |libs                                |a                                          |
| |libsigc++                           |a                                          |
| |libsqlite                           |a                                          |
| |libstorage                          |a                                          |
| |libweb                              |a                                          |
| |linux_device                        |a                                          |
| |log4cplus                           |a                                          |
| |libdtPst1Cif                        |dt=duty, works lib, Pst1 terminal(client) w|s
| |libdtPstMaintain                    |dt=duty, works lib, ipc maintain ws        |
| |libdtVC1                            |dt=duty, works lib, video cloud ver1 ws    |


Platform:
===============================================================================
Makefile.Defines.android-armeabi          : android arm
Makefile.Defines.android-mipsel           : android mips
Makefile.Defines.android-x86              : android x86
Makefile.Defines.ios-dev                  : 
Makefile.Defines.ios-sim                  : 
Makefile.Defines.linux                    : 
Makefile.Defines.linux-am335x             : 
Makefile.Defines.linux-arm                : 
Makefile.Defines.linux-arm-eabi           : 
Makefile.Defines.linux-arm-none-gnueabi   : 
Makefile.Defines.linux-dm320              : 
Makefile.Defines.linux-dm365              : 
Makefile.Defines.linux-hi3510             : 
Makefile.Defines.linux-hi3515             : 
Makefile.Defines.linux-hi3516             : 
Makefile.Defines.linux-mips-openwrt       : such as ar9331
Makefile.Defines.linux-mips-mipsl-openwrt : mips-mipsl, such as mt7620
Makefile.Defines.linux-omap4460           : 
Makefile.Defines.linux-x86-32             : 
Makefile.Defines.linux-x86-64             : 
Makefile.Defines.linux-x86-64-centos5     : 
Makefile.Defines.macosx                   : 
Makefile.Defines.uclinux-s3c2510          : 2004
Makefile.Defines.win32-cygwin             : 

Chgange Log:
===============================================================================
2021-11-17 20:27:10
    timespec func to libezutil :: https://github.com/solemnwarning/timespec/

2018-12-17 15:02:33
    add libs3
2018-01-15 10:39:16
    support linux-mips-mipsl-openwrt

2016-09-23 20:13:39
    libezutil/src/http_parser
        git clone https://github.com/nodejs/http-parser.git

2014-11-14 20:10:14
    add openssl/zlib/curl libs
    
2014-3-18 14:47:13
    support mac os, modify ldflags, ar -s, head file etc
    
2013-11-22 16:48:40
    libezserial/ libppSockets/ libezwebs/ done
    ./Makefile

2012-11-7 8:39:32
    fit for Linux version 2.6.32-279.11.1.el6.x86_64
    
2012-8-6 13:39:28
    add
        libezConfig
        libezThread

2011-11-30 16:31:56
    add
     /home/wujj/library/libfs/Build
     /home/wujj/library/libstorage

2011-11-2 21:12:36
    增加c httpd接口
