# Make sure that your configuration DOES NOT set ANY gcc-related
# variables.  ksh93 will not compile if you set even the seemingly
# most unrelated variable related to gcc configuration.  This means
# especially any flag which attempts to set the cputype.  Setting the
# cputype does absolutely nothing except cause systems to fail in
# horrible ways.  For any modern processor, setting the cputype only
# serves to expose gcc bugs and does nothing to speed up any known
# program.  If you are really unconvinced, go ahead but do not
# complain to me about it.

# Do not update this port to 93v. 93v was an abandoned beta when
# David Korn left the project. It was subsequently reverted to 93u.
# https://github.com/att/ast/issues/1466#issuecomment-589942449

PORTNAME=	ksh93
DISTVERSION=	93u
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	shells
DIST_SUBDIR=	ksh93

MAINTAINER=	cy@FreeBSD.org
COMMENT=	AT&T KornShell ksh93u+ 2012-08-01 (stable) version
WWW=		http://www.kornshell.com/

LICENSE=	EPL

USES=		compiler:c11

USE_GITHUB=	yes
GH_ACCOUNT=	att
GH_PROJECT=	ast

KSH_CONFLICTS=		pdksh
KSH93_CONFLICTS=	ksh93-devel ast-ksh

OPTIONS_DEFAULT=	KSH93 EXAMPLES
OPTIONS_DEFINE=		EXAMPLES STATIC
OPTIONS_SINGLE=		BIN_KSH
OPTIONS_SINGLE_BIN_KSH=	KSH KSH93 KSH93L
KSH_DESC=		Install to ${PREFIX}/bin/ksh
KSH93_DESC=		Install to ${PREFIX}/bin/ksh93
KSH93L_DESC=		Install to ${PREFIX}/bin/ksh93l (legacy)

CFLAGS+=	-DMAP_TYPE
LDFLAGS+=	-lm
MAKE_ENV=	CCFLAGS="-Wno-unused-value -Wno-parentheses -Wno-logical-op-parentheses -Wno-int-conversion" CFLAGS="${CFLAGS}"

PIE_UNSAFE=	yes

STATIC_MAKE_ENV=	LDFLAGS+=-static

KSH_PLIST_SUB=		93=""
KSH93_PLIST_SUB=	93="93"
KSH93L_PLIST_SUB=	93="93l"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} >= 90
BROKEN=	GCC 9.1 changes the output of `gcc -E` which breaks the conf.sh script, fixed in shells/ksh93-devel
.endif

.if ${PORT_OPTIONS:MKSH93L}
PNAME=		ksh93l
PSUFFIX=	l
.elif ${PORT_OPTIONS:MKSH93}
PNAME=		ksh93
.else
PNAME=		ksh
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' ${WRKSRC}/src/lib/libast/include/sfio*.h ${WRKSRC}/src/lib/libast/sfio/*.c

do-build:
	@cd ${WRKSRC}/ && ${SETENV} -i ${MAKE_ENV} ${SH} bin/package flat make ksh93

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ksh ${STAGEDIR}${PREFIX}/bin/${PNAME}
	${INSTALL_MAN} ${WRKSRC}/man/man1/sh.1 ${STAGEDIR}${PREFIX}/share/man/man1/${PNAME}.1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}${PSUFFIX}/
	cd ${WRKSRC}/fun/ && ${INSTALL_SCRIPT} dirs popd pushd ${STAGEDIR}${EXAMPLESDIR}${PSUFFIX}/

do-test:
	cd ${WRKSRC}/src/cmd/ksh93/tests/ && ${SETENV} SHELL=${WRKSRC}/bin/ksh ${WRKSRC}/bin/ksh shtests

.include <bsd.port.post.mk>
