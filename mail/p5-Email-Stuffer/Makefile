PORTNAME=	Email-Stuffer
PORTVERSION=	0.020
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	More casual approach to creating and sending Email
WWW=		https://metacpan.org/release/Email-Stuffer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Params-Util>=0.23:devel/p5-Params-Util \
		p5-File-Type>=0.22:devel/p5-File-Type \
		p5-Email-MIME>=1.901:mail/p5-Email-MIME \
		p5-Email-Sender>=0:mail/p5-Email-Sender

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
