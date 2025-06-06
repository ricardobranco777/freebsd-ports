PORTNAME=	compat12x
PORTVERSION=	12.2.1202000.20210406
PORTREVISION= 	2
CATEGORIES=	misc
MASTER_SITES=	LOCAL/jkim
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Convenience package to install the compat12x libraries

LICENSE=	BSD2CLAUSE

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}
NO_SHLIB_REQUIRES_GLOB=	libssh.*

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 12
IGNORE=		is for FreeBSD 12.x and newer
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400000
RUN_DEPENDS+=	compat13x-${ARCH}>=0:misc/compat13x
.endif

.if ${ARCH} == amd64
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
