PORTNAME=	cegobridge
PORTVERSION=	1.9.0
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Imports non-cego database dump files into cego
WWW=		https://www.lemke-it.com/

LIB_DEPENDS=	liblfcbase.so:devel/lfcbase \
		liblfcxml.so:devel/lfcxml \
		libcego.so:databases/cego

USES=		readline

LICENSE=	GPLv3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
PLIST_FILES=	bin/cegobridge

.include <bsd.port.mk>
