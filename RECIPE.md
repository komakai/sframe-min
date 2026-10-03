# RECIPE: sframe-min

How the `main-min` branch of this repository was made from upstream, and
everything that differs from it. It is a submodule of webrtc-third_party-min (at `sframe/src`) for [webrtc-min](https://github.com/komakai/webrtc-min).

## Upstream

- Repository: https://chromium.googlesource.com/external/github.com/cisco/sframe
- Revision: db604c8f1960dc2047f1d708d521b28dba058dc9 (2026-09-16T23:33:14+02:00)

The first commit on `main-min` is an unmodified snapshot of that revision, so
`git diff <first commit> main-min` shows every change made here.

## Stripped

Removed because nothing in the build needs them (run from the repository
root on the snapshot):

```sh
# Tests, fuzzers, CI, scripts, vcpkg manifests and the upstream CMake/make builds.
git rm -rq alternatives cmake fuzz .github scripts test
git rm -q CMakeLists.txt Makefile
```

## Deviations from upstream

- **`include/namespace.h`**: upstream's CMake generates it from
  `cmake/namespace.h.in`; it's checked in with the fixed `sframe` namespace,
  as Chromium's `third_party/sframe/namespace.h` does.
- **CMake** (commit "Add CMake build"): `CMakeLists.txt` replaces upstream's
  with Chromium's `third_party/sframe/BUILD.gn`: the `sframe` library with the
  BoringSSL backend only (`BORINGSSL`; a `boringssl` target from
  boringssl-min). The OpenSSL backends (`src/crypto_openssl*.cpp`) aren't
  built.

## Updating to a new upstream revision

`main-min` isn't a git fork of upstream (no upstream history), so updates are
re-applied rather than merged:

1. Replace the tree with upstream at the new revision and commit it as
   "Snapshot of upstream at <rev>" (`git rm -rq . && git archive` of the new
   revision, or a copy of a fresh checkout).
2. Re-run the strip commands above and commit.
3. Re-apply the deviation commits (`git cherry-pick` them from the previous
   `main-min` history) and fix up any conflicts.
4. Update the source lists in the CMake files for files upstream added,
   removed or renamed (compare with the new BUILD.gn in the snapshot commit),
   then build webrtc-min and compare with a gn build.
