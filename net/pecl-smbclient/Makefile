PORTNAME=	smbclient
PORTVERSION=	1.1.2
CATEGORIES=	net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Smbclient wrapper extension
WWW=		https://pecl.php.net/package/smbclient \
		https://github.com/eduardok/libsmbclient-php

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl samba:lib

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}
CPPFLAGS+=	-I${SAMBA_INCLUDEDIR}
LDFLAGS+=	-L${SAMBA_LIBDIR}

.include <bsd.port.mk>
