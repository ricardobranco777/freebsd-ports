PORTNAME=	pglast
PORTVERSION=	5.8
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	a.wolk@fudosecurity.com
COMMENT=	PostgreSQL Languages AST and statements prettifier
WWW=		https://github.com/lelit/pglast

LICENSE=	GPLv3+

BROKEN_riscv64=		fails to build: PostgreSQL does not have native spinlock support on this platform

USES=		gmake python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|make|gmake|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pglast/parser*.so

.include <bsd.port.mk>
