PORTNAME=	wasmer
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.0
CATEGORIES=	devel

MAINTAINER=	kjozic@gmail.com
COMMENT=	WebAssembly Runtime supporting WASIX, WASI and Emscripten
WWW=		https://wasmer.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only amd64 works so far (with some issues)

BUILD_DEPENDS=	bash>0:shells/bash \
		libffi>0:devel/libffi \
		zstd>0:archivers/zstd

USES=		cargo gmake llvm pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wasmerio

CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV+=	ENABLE_CRANELIFT=1 \
		ENABLE_LLVM=0 \
		ENABLE_SINGLEPASS=1 \
		ENABLE_V8=0 \
		ENABLE_WAMR=0 \
		ENABLE_WASMI=0

ALL_TARGET=	build-wasmer

RUSTFLAGS=	-L native=${LOCALBASE}/lib

PLIST_FILES=	bin/wasmer

pre-configure:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wasmer ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
