load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _ncurses_repository_impl(_ctx):
    http_archive(
        name = "ncurses",
        build_file = "//third_party/ncurses:ncurses.BUILD",
        #patch_args = ["-p1"],
        patches = [
            "//third_party/ncurses/patches:change_mode.patch",
            "//third_party/ncurses/patches:fail_on_error.patch",
        ],
        sha256 = "39893846139518e6c2d00ac1d354d4889f0f394acd44885d70b14eaef4e23e8e",
        strip_prefix = "ncurses-6.4",
        urls = [
            "https://github.com/mirror/ncurses/archive/refs/tags/v6.4.tar.gz",
        ],
    )

ncurses_repository = module_extension(implementation = _ncurses_repository_impl)
