PORTNAME=	alexandria
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of portable public domain utilities for Common Lisp
WWW=		https://common-lisp.net/project/alexandria/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cl
USE_GITLAB=	yes
GL_SITE=	https://gitlab.common-lisp.net

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sbcl:lang/sbcl \
			texi2pdf:print/texinfo
DOCS_USES=		tex
DOCS_USE=		TEX=latex:build
DOCS_INFO=		doc/${PORTNAME}

do-build:
	@${DO_NADA}

do-build-DOCS-on:
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} doc

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}-1 \
		${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}-2 \
		${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-1/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}-1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-2/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}-2
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-tests.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}.asd ${STAGEDIR}${ASDF_REGISTRY}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}-tests.asd ${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.html ${WRKSRC}/doc/${PORTNAME}.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
