PORTNAME=	azure-agent
PORTVERSION=	2.12.0.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	weh@microsoft.com
COMMENT=	Microsoft Azure Linux Agent
WWW=		https://github.com/Azure/WALinuxAgent/

LICENSE=	APACHE20

RUN_DEPENDS=	sudo:security/sudo \
		bash:shells/bash \
		dmidecode:sysutils/dmidecode \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss

NO_BUILD=	yes
USES=		python shebangfix

SHEBANG_FILES=	bin/waagent bin/waagent2.0

USE_GITHUB=	yes
GH_ACCOUNT=	Azure
GH_PROJECT=	WALinuxAgent
USE_PYTHON=	autoplist distutils noflavors

post-patch:
	${REINPLACE_CMD} -e "s,/etc/waagent,${PREFIX}/etc/waagent,g" \
		${WRKSRC}/azurelinuxagent/common/osutil/default.py
	${REINPLACE_CMD} -e "s,/etc/rc.d/waagent,${PREFIX}/etc/rc.d/waagent,g" \
			 -e "s,/etc/waagent,${PREFIX}/etc/waagent,g" \
			 -e "s,#!/usr/bin/env python,#!${PYTHON_CMD},g" \
			 -e "/command_interpreter/ s,/usr/local/bin/python,${PYTHON_CMD}," \
			 -e "s,/usr/sbin/waagent,${PREFIX}/sbin/waagent,g" \
		${WRKSRC}/bin/waagent2.0
	${REINPLACE_CMD} -e "s,:/usr/local/bin,:/usr/local/bin:/usr/local/sbin,g" \
			 -e "s,python,${PYTHON_CMD},g" \
		${WRKSRC}/init/freebsd/waagent
	${REINPLACE_CMD} -e "s,/usr/sbin,${PREFIX}/sbin,g" \
		${WRKSRC}/init/waagent
	${REINPLACE_CMD} -e "s,/etc/waagent,${PREFIX}/etc/waagent,g" \
			 -e "s,/usr/bin/python,${PYTHON_CMD},g" \
			 -e "s,/usr/sbin,${PREFIX}/sbin,g" \
		${WRKSRC}/init/waagent.service
	${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" \
			 -e "/set_conf_files.*freebsd\/waagent.conf/ s/^/#/" \
			 -e "s,/usr/sbin,${PREFIX}/sbin,g" \
		${WRKSRC}/setup.py

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/config/freebsd/waagent.conf \
		${STAGEDIR}${PREFIX}/etc/waagent.conf.sample

.include <bsd.port.mk>
