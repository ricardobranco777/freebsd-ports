PORTNAME=	smbnetfs
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	filesystems net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SMBNetFS-${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Mount smb shares (Fuse filesystem)
WWW=		https://sourceforge.net/projects/smbnetfs/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS LIBSECRET

LIBSECRET_DESC=	Use libsecret to store credentials
LIBSECRET_CONFIGURE_WITH=	libsecret
LIBSECRET_LIB_DEPENDS=	libsecret-*.so:security/libsecret

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

USES=		compiler:c11 fuse gnome iconv pkgconfig samba:lib tar:bzip2
USE_GNOME=	glib20:build

GNU_CONFIGURE=	yes
# A hack to disable gratuitous linking with -lglib-2.0
CONFIGURE_ENV+=	GLIB_LIBS=-L/var/empty
CFLAGS+=	-I${SAMBA_INCLUDEDIR} -DFUSE_USE_VERSION=${FUSE_VERSION}
LDFLAGS+=	-L${SAMBA_LIBDIR}
SUB_FILES=	pkg-message
# configure just generated config.h -- we do not need to redo it:
MAKE_ARGS+=	AUTOHEADER=${TRUE}

.include <bsd.port.pre.mk>

.if ${ICONV_LIB} == ""
CONFIGURE_ENV+=	ac_cv_lib_iconv_iconv_open=yes
CONFIGURE_ARGS+=--with-libiconv=native
.endif

# Uses/fuse.mk should be doing the below:
.if ${LIBFUSE_VER} == 3
CONFIGURE_ENV+=	FUSE_CFLAGS="-I${LOCALBASE}/include/fuse3" \
		FUSE_LIBS="-L${LOCALBASE}/lib -lfuse3"
FUSEPKG=	fuse3
LDFLAGS+=	-lthr
.else
FUSEPKG=	fuse
.endif
FUSE_VERSION=	"`pkgconf --modversion ${FUSEPKG} |	\
		    ${SED} -E 's,^([0-9]+)\.([0-9]+)\..*,\1\2,'`"

.include <bsd.port.post.mk>
