PORTNAME=	opustags
DISTVERSION=	1.10.1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	View and edit Ogg Opus comments
WWW=		https://github.com/fmang/opustags

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	compilation is broken with clang-19, see https://github.com/fmang/opustags/issues/73

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cmake compiler:c++20-lang iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fmang

TEST_TARGET=	check # 1 test fails, see https://github.com/fmang/opustags/issues/60

PLIST_FILES=	bin/opustags \
		share/man/man1/opustags.1.gz

.include <bsd.port.mk>
