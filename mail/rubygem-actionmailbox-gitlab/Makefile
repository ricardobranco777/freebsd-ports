PORTNAME=	actionmailbox
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Receive and process incoming emails in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actionmailbox \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack-gitlab \
		rubygem-activejob-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob-gitlab \
		rubygem-activerecord-gitlab>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord-gitlab \
		rubygem-activestorage-gitlab>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage-gitlab \
		rubygem-activesupport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport-gitlab \
		rubygem-mail>=2.7.1,2:mail/rubygem-mail \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-pop>=0:mail/rubygem-net-pop \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
