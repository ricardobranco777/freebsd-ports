PORTNAME=	sidekiq-unique-jobs
PORTVERSION=	8.0.11
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ensure only a single copy of a job is in Redis
WWW=		https://github.com/mhenrixon/sidekiq-unique-jobs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.5<2:devel/rubygem-concurrent-ruby \
		rubygem-sidekiq>=7.0.0<9.0.0:devel/rubygem-sidekiq \
		rubygem-thor>=1.0<3.0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/uniquejobs

.include <bsd.port.mk>
