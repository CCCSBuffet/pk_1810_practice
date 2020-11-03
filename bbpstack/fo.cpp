#include <fstream>
#include <cstdlib>

using namespace std;

/*	FlexibleOpen() will attempt to open the file given in `path` for reading (or
	writing depending on `mode`). The file will be attempted locally first - that
	is, as given in `path`. If this fails, the environment variable `envval` will
	be prepended to `path` and the open is attempted again.

	In zsh and bash, define the environment variable by:
	$ export VARNAME=path

	Put this in an rc file to make sticky. Real example:
	$ export CSC1810=~/Documents/csc1810_files

	In Windows, edit the environment variables directly using the UI. Note that
	Visual Studio must be restarted for it to pick up the newest values.
*/

fstream FlexibleOpen(string path, ios::openmode mode, string envval) {
	fstream file;
	string slash = "/";

	// Check for local open.
	file.open(path, mode);
	if (!file.is_open()) {
		/*	Check environment variable. Unfortunately, this is done with platform
			specific code. On Mac, this can  be done using the oldest form of getenv.
			On Windows, getenv is deprecated.
		*/
		string envvar;
#if defined(_WIN64) || defined(WIN32)
		/*	On Windows, the safer getenv_s is used. It follows the "call me twice"
			pattern. The first time, call with a null destination buffer and only
			the space needed will be filled in. Then call a second time to actually
			get the value.
		*/
		size_t space_needed;
		slash = "\\";
		getenv_s(&space_needed, nullptr, 0, envval.c_str());
		if (space_needed > 0) {
			// Null termination will be done by `string`.
			envvar.resize(space_needed - 1);
			getenv_s(&space_needed, (char*) envvar.c_str(), space_needed, envval.c_str());
		}
#else
		char * p = getenv(envval.c_str());
		if (p) {
			envvar = string(p);
		}
#endif
		if (!envvar.empty()) {
			if (envvar.at(envvar.size() - 1) != '/') {
				envvar = envvar + slash;
			}
			envvar = envvar + path;
			file.open(envvar, mode);
		}
	}
	return file;
}
