PORTNAME=	abx
DISTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://phintsan.kapsi.fi/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple ABX tester to compare audio files with GUI
WWW=		https://phintsan.kapsi.fi/abx.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile

USES=		gettext-runtime gmake gnome pkgconfig
USE_GNOME=	atk cairo glib20 gdkpixbuf gtk20 pango

GNU_CONFIGURE=	yes

LDFLAGS+=	-lm

PLIST_FILES=	bin/abx

.include <bsd.port.mk>
