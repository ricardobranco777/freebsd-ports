PORTNAME=	libthmap
PORTVERSION=	g2020082801
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Concurrent trie-hash map library
WWW=		https://github.com/rmind/thmap

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		compiler:c11 gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_PROJECT=	thmap
GH_TAGNAME=	8149b27
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		INCDIR=${LOCALBASE}/include \
		LIBDIR=${LOCALBASE}/lib \
		MANDIR=${LOCALBASE}/share/man

.include <bsd.port.mk>
