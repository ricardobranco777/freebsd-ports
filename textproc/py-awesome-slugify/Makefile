PORTNAME=	awesome-slugify
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Flexible slugify function
WWW=		https://pypi.org/project/awesome-slugify/

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04.14:converters/py-unidecode@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
TEST_TARGET=	do-test
NOSETESTS=	nosetests-${PYTHON_VER}

do-test:
	${NOSETESTS} ${STAGEDIR}${PYTHON_SITELIBDIR}/slugify

.include <bsd.port.mk>
