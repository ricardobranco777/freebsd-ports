PORTNAME=	jlatexmath
PORTVERSION=	1.0.7
CATEGORIES=	math java
MASTER_SITES=	https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath/${PORTVERSION}/:0 \
		https://repo1.maven.org/maven2/org/scilab/forge/jlatexmath-fop/${PORTVERSION}/:1
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar:0 \
		${PORTNAME}-fop-${PORTVERSION}.jar:1
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API to display mathematical formulas written in LaTeX
WWW=		https://wiki.scilab.org/JLaTeXMath

LICENSE=	GPLv2

RUN_DEPENDS=	${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
.for f in jlatexmath jlatexmath-fop
	${INSTALL_DATA} ${DISTDIR}/${f}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${f}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${f}.jar
.endfor

.include <bsd.port.mk>
