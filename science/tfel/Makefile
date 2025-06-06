PORTNAME=	tfel
PORTVERSION=	4.0.0
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
PKGNAMESUFFIX=	-mfront

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge
WWW=		https://github.com/thelfer/tfel

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake compiler:c++0x fortran

CONFLICTS_INSTALL=	tfel-mfront-edf-3.*

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	DOCS PYTHON

OPTIONS_SUB=		yes

PYTHON_USES=		localbase python
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_LIB_DEPENDS=	${PY_BOOST}	\
			libboost_thread.so:devel/boost-libs
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_CMAKE_BOOL=	enable-python enable-python-bindings

CMAKE_ON=	enable-aster enable-calculix enable-fortran
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" -DCOMPILER_FLAGS="${CFLAGS}"
PLIST_SUB=	VER=${PORTVERSION}
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/include/NUMODIS/Math/Utilities.hxx \
		${WRKSRC}/include/TFEL/Math/General/Abs.hxx
	@${REINPLACE_CMD} -e 's|std::binary_function|std::__binary_function|' \
		${WRKSRC}/include/TFEL/Math/General/AbsCompare.hxx
.endif

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include <bsd.port.post.mk>
