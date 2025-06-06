PORTNAME=	lilypond
DISTVERSION=	2.24.4
PORTREVISION=	1
CATEGORIES=	print audio
MASTER_SITES=	http://lilypond.org/download/source/v${DISTVERSION:R}/

MAINTAINER=	m.ne@gmx.net
COMMENT=	GNU music typesetter
WWW=		https://lilypond.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		dblatex:textproc/dblatex \
		fontforge:print/fontforge \
		help2man:misc/help2man \
		pdftexi2dvi:print/texinfo \
		pngtopnm:graphics/netpbm \
		rsync:net/rsync \
		t1ascii:print/t1utils \
		texi2html:textproc/texi2html \
		zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans-Bold.ttf:x11-fonts/dejavu \
		mftrace:print/mftrace \
		urw-base35-fonts>0:x11-fonts/urw-base35-fonts

USES=		bison:build compiler:c++11-lib cpe gettext-tools ghostscript \
		gmake gnome magick:7,build perl5 pkgconfig python
USE_CXXSTD=	c++14
USE_GNOME=	pango
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_prog_MAKEINFO="${LOCALBASE}/bin/makeinfo" \
		FLEX=${FLEX} \
		GUILE_FLAVOR=guile-${GUILE_VER} \
		HOME=${WRKDIR} \
		YACC=${YACC}

MAKEFILE=	GNUmakefile
ALL_TARGET=	all

CONFLICTS_INSTALL=	lilypond-devel

BINARY_ALIAS=	python=${PYTHON_VERSION}

INFO=		lilypond-changes \
		lilypond-contributor \
		lilypond-essay \
		lilypond-extending \
		lilypond-internals \
		lilypond-learning \
		lilypond-notation \
		lilypond-snippets \
		lilypond-usage \
		music-glossary
PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	GUILE2
OPTIONS_SINGLE=		GUILE
OPTIONS_SINGLE_GUILE=	GUILE2 GUILE3
OPTIONS_SUB=		yes

GUILE2_DESC=	Use guile2
GUILE3_DESC=	Use guile3

GUILE2_USES=	guile:2.2
GUILE3_USES=	guile:3.0
NLS_USES=	gettext-runtime

post-patch:
	@${SED} -e 's|%%FONTDIR%%|${WRKDIR}/fontconfig/cache/|' \
		${FILESDIR}/fonts.conf > ${WRKDIR}/.fonts.conf

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/po \\$$/d' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilypond
	(cd ${STAGEDIR}/${DATADIR} && ${LN} -fs ${DISTVERSION} current)

.include <bsd.port.mk>
