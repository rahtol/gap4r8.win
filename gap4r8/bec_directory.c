#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>


DIR *opendir (const char *pathname)
{
	if (/* pathname is not a directory */ 0) {
		return NULL;
	}

	DIR *d = (DIR *) malloc (sizeof(DIR));
	size_t len = strlen (pathname);
	d->__d_dirname = (char *)malloc (len+2);
	strcpy_s (d->__d_dirname, len+1, pathname);
	d->__d_dirname[len] = '*';
	d->__d_dirname[len+1] = 0;
	d->__d_position = 0;
	d->__handle = (struct _finddata_t *) malloc(sizeof(struct _finddata_t));
	d->__d_dirent = (struct dirent *) malloc(sizeof(struct dirent));

	return d;
};

struct dirent *readdir (DIR *d)
{
	struct _finddata_t *pFindData = (struct _finddata_t *) d->__handle;

	if (d->__d_position == 0) {
		if ((d->__d_internal = _findfirst(d->__d_dirname, pFindData)) == -1L) {
			if (errno == ENOENT) errno = 0;
			return NULL;
		}
	}
	else {
		if (_findnext(d->__d_internal, d->__handle) != 0) {
			if (errno == ENOENT) errno = 0;
			return NULL;
		}
	}

	d->__d_position += 1;
	strcpy_s(d->__d_dirent->d_name, NAME_MAX, pFindData->name);
	// TODO: copy other infos (attr, times ...) as well

	return d->__d_dirent;
};

int closedir (DIR *d)
{
	int rc = _findclose (d->__d_internal);
	free(d->__d_dirname);
	free(d->__handle);
	free(d->__d_dirent);
	free(d);
	return rc;
};

