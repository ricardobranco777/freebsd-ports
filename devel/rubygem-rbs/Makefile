PORTNAME=	rbs
PORTVERSION=	3.9.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Language for type signatures for Ruby and standard library definitions
WWW=		https://github.com/ruby/rbs

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-logger>=0:devel/rubygem-logger

USES=		gem

PLIST_FILES=	bin/rbs

.include <bsd.port.mk>
