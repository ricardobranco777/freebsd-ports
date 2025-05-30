PORTNAME=	mysql-connector-java
PORTVERSION=	5.1.49
CATEGORIES=	databases java
MASTER_SITES=	MYSQL/Connector-J
PKGNAMESUFFIX=	51

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	MySQL Connector/J: JDBC interface for MySQL
WWW=		https://dev.mysql.com/downloads/connector/j/

LICENSE=	GPLv2

RUN_DEPENDS=	${JAVALIBDIR}/log4j.jar:devel/log4j

# 8.0.x is now the GA release, but drops support for java 1.6 and 1.7
PORTSCOUT=	limit:^5\.1\..*

USES=		cpe java
CPE_VENDOR=	oracle
CPE_PRODUCT=	mysql_connector_j

CONFLICTS_INSTALL=	mysql-connector-java # share/java/classes/mysql-connector-java.jar

NO_ARCH=	yes
JAVA_VERSION=	8
BUILDDIR=	${WRKDIR}/${DISTNAME}
APIDOCSDIR=	${STAGEDIR}${DOCSDIR}/javadoc
SRCDIR=		${WRKDIR}/${DISTNAME}/src
JAVADOCDIR=	${WRKDIR}/${DISTNAME}/javadoc
DESTJARFILE=	${PORTNAME}.jar
EXTRADOCS=	CHANGES
JARFILE=	${DISTNAME}-bin.jar
JDCLASSPATH=	${SRCDIR}:${CLASSPATH}

PLIST_FILES=	${JAVAJARDIR}/${DESTJARFILE}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.pre.mk>

do-build:
	@${DO_NADA}

do-build-DOCS-on:
.if ${JAVA_PORT_VERSION:M*8*}
	@${ECHO_MSG} "NOTE>>> Generating javadoc is broken with JDK 1.8+"
.else
	@${MKDIR} ${JAVADOCDIR} && (cd ${SRCDIR};               \
	    ${JAVADOC} -quiet -breakiterator -encoding utf8     \
	    -d ${JAVADOCDIR} -package -classpath ${JDCLASSPATH}	\
	    com.mysql.jdbc org.gjt.mm.mysql)
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing .jar files..."
	${INSTALL_DATA} ${BUILDDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@for extradoc in ${EXTRADOCS} ; do                          \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/$$extradoc ${STAGEDIR}${DOCSDIR} ; \
	done
.if ${JAVA_PORT_VERSION:N*8*}
	@${MKDIR} ${STAGEDIR}${APIDOCSDIR}
	@cd ${JAVADOCDIR} && ${COPYTREE_SHARE} . ${APIDOCSDIR}
.endif
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
