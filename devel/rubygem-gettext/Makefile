PORTNAME=	gettext
PORTVERSION=	3.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby implementation of the gettext library
WWW=		https://ruby-gettext.github.io/ \
		https://github.com/ruby-gettext/gettext

LICENSE=	LGPL3+ RUBY
LICENSE_COMB=	dual
LICENSE_FILE_LGPL3+ =	${WRKSRC}/doc/text/lgpl-3.0.txt
LICENSE_FILE_RUBY=	${WRKSRC}/doc/text/ruby-license.txt

RUN_DEPENDS=	rubygem-erubi>=0:www/rubygem-erubi \
		rubygem-locale>=2.0.5:devel/rubygem-locale \
		rubygem-prime>=0:math/rubygem-prime \
		rubygem-racc>=0:devel/rubygem-racc \
		rubygem-text>=1.3.0:textproc/rubygem-text

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/rmsgcat \
		bin/rmsgfmt \
		bin/rmsginit \
		bin/rmsgmerge \
		bin/rxgettext

SHEBANG_FILES=	samples/*.rb samples/cgi/*.rb

.include <bsd.port.mk>
