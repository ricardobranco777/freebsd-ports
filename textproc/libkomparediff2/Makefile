PORTNAME=	libkomparediff2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to compare files and strings
WWW=		https://www.kde.org

USES=		cmake compiler:c++11-lang gettext kde:6 \
		qt:6 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons i18n kio parts \
		service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
