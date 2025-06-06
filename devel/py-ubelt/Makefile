PORTNAME=	ubelt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python utility belt containing simple tools
WWW=		https://github.com/Erotemic/ubelt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		cmake:devel/cmake-core
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.0.15:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=1.4.2:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdoctest>=1.1.2:devel/py-xdoctest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>0:devel/py-xxhash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Erotemic

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
