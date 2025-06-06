PORTNAME=	symengine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
CATEGORIES=	math python
#MASTER_SITES=	PYPI # latest release isn't compatible with math/symengine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library providing wrappers to SymEngine
WWW=		https://symengine.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libarb.so:math/arb \
		libecm.so:math/gmp-ecm \
		libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libsymengine.so:math/symengine \
		libzstd.so:archivers/zstd
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} # see https://github.com/symengine/symengine.py/issues/416

USES=		cmake compiler:c++11-lang llvm:15 python
USE_PYTHON=	cython flavors pytest

USE_GITHUB=	yes
GH_PROJECT=	symengine.py

BINARY_ALIAS=	python=${PYTHON_CMD} # cmake scripts expect python executable

# cmake scripts copy build type and flags from math/symengine, and ignore all local variables of that kind

# tests as of 0.14.0: 363 passed, 1 skipped, 1 warning in 7.76s

.include <bsd.port.mk>
