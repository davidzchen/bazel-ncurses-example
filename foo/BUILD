package(default_visibility = ["//visibility:public"])

cc_library(
    name = "color",
    srcs = ["color.cc"],
    hdrs = ["color.h"],
    deps = [
        "@ncurses",
        "@ncurses//:ncurses_headers",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":color",
        "@ncurses",
        "@ncurses//:ncurses_headers",
    ],
)
