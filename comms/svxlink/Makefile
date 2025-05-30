PORTNAME?=	svxlink
PORTVERSION=	19.09.2
PORTREVISION?=	2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT?=	General purpose ham radio voice services
WWW=		https://www.svxlink.org/

LICENSE?=	GPLv2

LIB_DEPENDS?=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libgsm.so:audio/gsm \
		libopus.so:audio/opus \
		libpopt.so:devel/popt \
		librtlsdr.so:comms/rtl-sdr \
		libspeex.so:audio/speex
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES+=		cmake:noninja compiler:c++11-lang gnome groff pkgconfig tcl:86
USE_GITHUB=	yes
GH_ACCOUNT=	sm0svx
GH_PROJECT=	svxlink

USE_GNOME=	libsigc++20

CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DLOCAL_STATE_DIR=/var \
		-DLOCALBASE:STRING="${LOCALBASE}" \
		-DMAN_INSTALL_DIR:FILEPATH=${PREFIX}/share/man

.if ${PORTNAME} == svxlink
USERS=		svxlink
GROUPS=		svxlink
USE_RC_SUBR=	remotetrx svxlink svxreflector
CMAKE_ARGS+=	-DUSE_QT:BOOL=NO
.endif
USE_LDCONFIG=	yes

ALL_TARGET?=		all man
OPTIONS_DEFINE=		DOCS DOXYGEN STATIC
STATIC_DESC=		Build and install static libraries
STATIC_CMAKE_ON=	-DBUILD_STATIC_LIBS=YES
.if ${PORTNAME} == svxlink
OPTIONS_DEFAULT=	ALSA OSS
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA OSS
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA
OSS_CMAKE_BOOL=		USE_OSS
.endif
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_ALL_TARGET=	doc
DOXYGEN_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
OPTIONS_SUB=		yes
PORTDOCS=		*

post-patch:
	@${GREP} -lr /dev/ttyS0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|/dev/ttyS0|/dev/ttyu0|'
	@${REINPLACE_CMD} -e 's|/usr/share/icons|${PREFIX}/share/icons|' \
		${WRKSRC}/src/qtel/qtel.desktop
	@${REINPLACE_CMD} -e 's|/usr/share/svxlink|${DOCSDIR}|' \
		${WRKSRC}/src/doc/man/svxlink.conf.5
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|' ${WRKSRC}/src/qtel/qtel.desktop \
		${WRKSRC}/src/doc/man/svxlink.conf.5 \
		${WRKSRC}/src/svxlink/svxlink/svxlink.conf.in
	@${REINPLACE_CMD} -e 's|/usr/lib|${PREFIX}/lib|' \
		${WRKSRC}/src/doc/man/svxlink.conf.5
post-patch-OSS-on:
	@${GREP} -lr alsa:default ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:default|oss:/dev/dsp|'
	@${GREP} -lr alsa:plughw:0 ${WRKSRC} | ${GREP} -v .bak | ${GREP} -v .orig | ${XARGS} \
		${REINPLACE_CMD} -e 's|alsa:plughw:0|oss:/dev/dsp|'

.if ${PORTNAME} == svxlink
post-install:
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/.procmailrc \
		${STAGEDIR}${PREFIX}/etc/svxlink/.procmailrc.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/gpio.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/gpio.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/TclVoiceMail.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/TclVoiceMail.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/remotetrx.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/remotetrx.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxreflector.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxreflector.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleDtmfRepeater.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleDtmfRepeater.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleEchoLink.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleEchoLink.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleFrn.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleFrn.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleHelp.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleHelp.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleMetarInfo.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleMetarInfo.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleParrot.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleParrot.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModulePropagationMonitor.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModulePropagationMonitor.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleSelCallEnc.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleSelCallEnc.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTclVoiceMail.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTclVoiceMail.conf.sample
	${MV}	${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTrx.conf \
		${STAGEDIR}${PREFIX}/etc/svxlink/svxlink.d/ModuleTrx.conf.sample
	${INSTALL} -d   ${STAGEDIR}/var/spool/svxlink

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/doc/README-19.09.adoc ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORTNAME} == qtel
post-install:
	${RM}	${STAGEDIR}${PREFIX}/include/svxlink/CppStdCompat.h
	${RM}	${STAGEDIR}${PREFIX}/include/svxlink/common.h
	${RM}	${STAGEDIR}${PREFIX}/lib/libsvxmisc.a
.endif

.include <bsd.port.mk>
