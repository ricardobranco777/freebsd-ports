PORTNAME=	libcli
PORTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates a Cisco style command-line interface
WWW=		https://github.com/dparrish/libcli/

LICENSE=	LGPL21

DEPRECATED=     Outdated and unmaintained in tree for years
EXPIRATION_DATE=2025-06-30

USES=		alias gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	dparrish

PLIST_FILES=	lib/libcli.so \
		lib/libcli.so.1.9.6 \
		lib/libcli.so.1.9 \
		lib/libcli.so.19 \
		include/libcli.h

.include <bsd.port.mk>
