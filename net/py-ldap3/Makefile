PORTNAME=	ldap3
PORTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Strictly RFC 4511 conforming LDAP V3 pure Python client
WWW=		https://github.com/cannatag/ldap3

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
