PORTNAME=	x42-plugins
DISTVERSION=	20240611 # the version is published here: http://gareus.org/misc/x42-plugins.php
CATEGORIES=	audio
MASTER_SITES=	http://gareus.org/misc/x42-plugins/
PKGNAMESUFFIX=	-lv2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # only to allow USE_GITHUB=nodefault for zita4 compatilility patch

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins (submodules)
WWW=		https://github.com/x42/x42-plugins/

LICENSE=	GPLv2

BROKEN_i386=	compilation fails: unsupported option '--fast-math'; did you mean '-ffast-math', reported to the author on 2022-11-06

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		bash:shells/bash
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libltc.so:audio/libltc \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libzita-convolver.so:audio/zita-convolver

USES=		compiler:c++11-lang gl gmake gnome localbase pkgconfig tar:xz \
		shebangfix xorg
USE_GNOME=	glib20 pango cairo
USE_XORG=	x11
USE_GL=		glu gl

USE_GITHUB=	nodefault
GH_TUPLE=	x42:convoLV2:ff291a3:x/convoLV2zita4

MAKE_ENV=	BUILDOPENGL=yes BUILDGTK=no LV2DIR=${PREFIX}/lib/lv2 MANDIR=${PREFIX}/share/man/man1
SHEBANG_FILES=	stepseq.lv2/gridgen.sh

CXXFLAGS+=	-std=c++98

CONFLICTS_INSTALL=	phaserotate-lv2 # lib/lv2/phaserotate.lv2/phaserotate.so

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_MAKE_ARGS=	PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

post-patch:
	@${REINPLACE_CMD} 's| -O3||' \
		${WRKSRC}/*.lv2/Makefile
	@cd ${WRKSRC} && ${RM} -r convoLV2 && ${MV} convoLV2zita4 convoLV2
	@${REINPLACE_CMD} 's| -msse -msse2 -mfpmath=sse| $$(PORT_SIMD_FLAGS)|' \
		${WRKSRC}/*.lv2/Makefile ${WRKSRC}/convoLV2/Makefile

.include <bsd.port.mk>
