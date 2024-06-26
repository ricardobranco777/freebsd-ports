PORTNAME=	bsdconfig
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/bsdconfig/
DISTNAME=	${PORTNAME}.130705

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-${PORTVERSION}.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to configure various aspects of FreeBSD
WWW=		https://druidbsd.sourceforge.net/

LICENSE=	BSD2CLAUSE

USES=		tar:txz uidfix
NO_WRKSUBDIR=	yes
PORTEXAMPLES=	browse_packages.sh bsdconfigrc

BSDCFG_LIBE=	libexec/bsdconfig
BSDCFG_SHARE=	share/bsdconfig

MAKE_ARGS+=	LIBEXECDIR="${PREFIX}/libexec" \
		MANDIR="${PREFIX}/share/man/man" \
		SBINDIR="${PREFIX}/sbin" \
		SHAREDIR="${PREFIX}/share"

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		is a FreeBSD-specific port
.endif

post-patch:
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LOCAL_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_SHARE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_SHARE=\).*|\1"${PREFIX}/share/${PORTNAME}"|'
	@${REINPLACE_CMD} \
		-e 's|^\(BSDCONFIG=\).*|\1${PREFIX}/sbin/${PORTNAME}|' \
		${WRKSRC}/dot/dot

.include <bsd.port.post.mk>
