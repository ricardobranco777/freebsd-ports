PORTNAME=	moarchiving
PORTVERSION=	1.0.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Biobjective Archive class with hypervolume indicator and uncrowded hypervolume improvement computation
WWW=		https://github.com/CMA-ES/moarchiving

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.4.0:devel/py-sortedcontainers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ARBITRARY_PRECISION
ARBITRARY_PRECISION_DESC=	Arbitrary precision hypervolume computation support

ARBITRARY_PRECISION_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}fraction>=0:math/py-fraction@${PY_FLAVOR}

.include <bsd.port.mk>
