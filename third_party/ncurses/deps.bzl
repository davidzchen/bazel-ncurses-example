"""
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _deps(_ctx):
    http_archive(
        name = "upstream",
        build_file_content = """
package(default_visibility = ["//visibility:public"])

filegroup(
    name = "srcs",
    srcs = glob(
        include = ["**"],
        exclude = ["*.bazel"],
    ),
)
        """,
        patch_args = ["-p1"],
        patches = [
            # The Configure script doesn't handle tilde in paths, which we are
            # using via bzlmode.
            "//:patches/tilde-paths.patch",
            # The configure script passes -stats and -lc to the linker, which
            # our linker doesn't support and we don't need.
            "//:patches/zig-ld.patch",
            # The configure hardcodes ar flags that are acceptable, but we want
            # to allow others.
            "//:patches/arflags.patch",
        ],
        sha256 = "39893846139518e6c2d00ac1d354d4889f0f394acd44885d70b14eaef4e23e8e",
        strip_prefix = "ncurses-6.4",
        urls = [
            "https://github.com/mirror/ncurses/archive/refs/tags/v6.4.tar.gz",
        ],
    )

deps = module_extension(implementation = _deps)
