PORTNAME=	gpsprune
PORTVERSION=	25.2
CATEGORIES=	astro java
MASTER_SITES=	https://activityworkshop.net/software/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Application for viewing, editing, and converting GPS coordinate data
WWW=		https://activityworkshop.net/software/gpsprune/

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

USES=		java
JAVA_VERSION=	11+

SUB_FILES=	gpsprune.sh
SUB_LIST=	JAVA="${JAVA}" JARNAME="${DISTNAME}"

PLIST_FILES=	bin/gpsprune ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

OPTIONS_DEFINE=	JAVA3D
JAVA3D_DESC=	Support for 3D view of track

JAVA3D_RUN_DEPENDS=	java3d>=1.5.2:java/java3d
JAVA3D_BROKEN=	java3d does not support java 11+

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/gpsprune.sh ${STAGEDIR}${PREFIX}/bin/gpsprune

.include <bsd.port.mk>
