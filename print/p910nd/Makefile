PORTNAME=	p910nd
PORTVERSION=	0.97
PORTREVISION=	2
CATEGORIES=	print net

MAINTAINER=	skozlov@FreeBSD.org
COMMENT=	Port 9100+n printer daemon
WWW=		https://github.com/kenyapcomau/p910nd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	kenyapcomau

ALL_TARGET=	${PORTNAME}

USE_RC_SUBR=	p910nd

P910ND_RUNDIR=	/var/run/${PORTNAME}
PLIST_SUB=	P910ND_RUNDIR=${P910ND_RUNDIR}

MAKE_ENV+=	USE_WRAP=yes

CFLAGS+=	-DLOCKFILE_DIR='\"${P910ND_RUNDIR}\"'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${MKDIR} ${STAGEDIR}${P910ND_RUNDIR}

.include <bsd.port.mk>
