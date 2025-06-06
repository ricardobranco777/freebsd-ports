PORTNAME=	kerchunk
PORTVERSION=	0.2.7
CATEGORIES=	filesystems python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Functions to make reference descriptions for ReferenceFileSystem
WWW=		https://fsspec.github.io/kerchunk/ \
		https://github.com/fsspec/kerchunk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numcodecs>=0:misc/py-numcodecs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>=0:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zarr>=0.1<3,1:devel/py-zarr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CFTIME FITS GRIB2 HDF NETCDF3
CFTIME_DESC=	Time handling support
FITS_DESC=	FITS file format support
GRIB2_DESC=	GRIB2 file format support
HDF_DESC=	HDF file format support
NETCDF3_DESC=	netCDF 4 file format support

CFTIME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cftime>=0:devel/py-cftime@${PY_FLAVOR}
FITS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xarray>=0:devel/py-xarray@${PY_FLAVOR}
GRIB2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cfgrib>=0:science/py-cfgrib@${PY_FLAVOR}
HDF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=0:science/py-h5py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xarray>=0:devel/py-xarray@${PY_FLAVOR}
NETCDF3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0,1:science/py-scipy@${PY_FLAVOR}

.include <bsd.port.mk>
