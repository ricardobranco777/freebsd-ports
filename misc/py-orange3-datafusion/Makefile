PORTNAME=	orange3-datafusion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11-7
PORTREVISION=	6
DISTVERSIONSUFFIX=	-g69aa51c
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data fusion add-on for Orange3
WWW=		https://github.com/biolab/orange3-datafusion

LICENSE=	GPLv3

DEPRECATED=	Depends on expiring misc/orange3
EXPIRATION_DATE=2025-06-21

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}scikit-fusion>0:misc/py-scikit-fusion@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
