PORTNAME=	Crypt-Curve25519
PORTVERSION=	0.08
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate shared secret using elliptic-curve Diffie-Hellman function
WWW=		https://metacpan.org/release/Crypt-Curve25519

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_mips=	fails to build: -m32 flag is not supported by this configuration
BROKEN_mips64=	fails to build: -m32 flag is not supported by this configuration

USES=		perl5 ssl
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Curve25519/Curve25519.so

.include <bsd.port.mk>
