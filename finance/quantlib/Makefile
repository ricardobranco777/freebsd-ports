PORTNAME=	quantlib
PORTVERSION=	1.38
CATEGORIES=	finance math devel
MASTER_SITES=	https://github.com/lballabio/QuantLib/releases/download/v${PORTVERSION}/
DISTNAME=	QuantLib-${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	C++ library for quantitative finance
WWW=		https://www.quantlib.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	${LOCALBASE}/include/boost/numeric/ublas/matrix.hpp:devel/boost-libs

USES=		compiler:c++17-lang libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV+=	EMACS=no
MAKE_ENV+=	AM_MAKEFLAGS=${_MAKE_JOBS}
TEST_TARGET=	check-examples check
TEST_ARGS+=	-j1	# Tests use OpenMP - do not parallelize them
TEST_ENV+=	OMP_NUM_THREADS=${MAKE_JOBS_NUMBER}
OPTIONS_SUB=	please

OPTIONS_DEFAULT=OPENMP EXAMPLES BENCHMARK THREAD_SAFE_OBSERVER_PATTERN

OPTIONS_DEFINE=	TRACING INDEXED_COUPONS
OPTIONS_DEFINE+=EXTRA_SAFETY_CHECKS SESSIONS INTRADAY
OPTIONS_DEFINE+=THREAD_SAFE_SINGLETON_INIT
OPTIONS_DEFINE+=THROWING_IN_CYCLES
OPTIONS_DEFINE+=${OPTIONS_DEFAULT}

BENCHMARK_DESC=		Install benchmark (it is always built)
EXTRA_SAFETY_CHECKS_DESC=Trade performance for run-time checks
INDEXED_COUPONS_DESC=	Use indexed rather than par coupons
INTRADAY_DESC=		Time precision of usecs, instead of days
TRACING_DESC=		Trade performance for more detailed errors
SESSIONS_DESC=		See help (F1)
THREAD_SAFE_OBSERVER_PATTERN_DESC=See help (F1)
THREAD_SAFE_SINGLETON_INIT_DESC=See help (F1)
THROWING_IN_CYCLES_DESC=	See help (F1)

EXAMPLES_CONFIGURE_WITH=lispdir=${EXAMPLESDIR}
CONFIGURE_ARGS+=	--disable-unity-build
CONFIGURE_ARGS+=	--enable-parallel-unit-test-runner
CONFIGURE_ARGS+=	--enable-null-as-functions
CONFIGURE_ARGS+=	--with-boost-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-boost-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-std-any
CONFIGURE_ARGS+=	--enable-std-classes # Prefer C++11 to Boost
CONFIGURE_ARGS+=	--enable-std-optional
CONFIGURE_ARGS+=	--enable-std-pointers
CONFIGURE_ARGS+=	--enable-test-suite

.for o in ${OPTIONS_DEFINE}
$o_CONFIGURE_ENABLE=	${o:S/_/-/g:tl}
.endfor

CXXFLAGS+=	-std=c++17
CXXFLAGS_i386=	-DBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS

.include <bsd.port.mk>
