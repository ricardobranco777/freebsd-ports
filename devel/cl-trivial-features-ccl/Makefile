PORTNAME=	trivial-features
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-4
DISTVERSIONSUFFIX=	-gd249a62
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
DISTFILES=	# none

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Ensures consistent *FEATURES* in Common Lisp
WWW=		https://www.cliki.net/trivial-features

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features
RUN_DEPENDS=	${LOCALBASE}/${CL_LIBDIR_REL}/trivial-features/trivial-features.asd:devel/cl-trivial-features

USES=		cl
FASL_TARGET=	ccl

.include <bsd.port.mk>
