PORTNAME=	prosody-modules
DISTVERSION=	20250402
CATEGORIES=	net-im
MASTER_SITES=	https://hg.prosody.im/${PORTNAME}/archive/
DISTNAME=	f315edc39f3d
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Prosody Community modules repository snapshot
WWW=		https://modules.prosody.im/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	prosodyctl:net-im/prosody

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	INSTALLPATH=${INSTALLPATH}
WRKSRC=		${WRKDIR}/Community-Modules-${DISTNAME}
INSTALLPATH=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLPATH} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} 'mod_*' ${STAGEDIR}${INSTALLPATH}/
	@cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}

add-plist-post:
	# Regenerate .PLIST.pymodtemp to get all installed files from
	# ${STAGEDIR}.
	@${FIND} ${STAGEDIR} -type f -o -type l | \
		${SORT} -u | ${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.mktmp

.include <bsd.port.mk>
