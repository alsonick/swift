//===--- PrintClangFunction.h - Printer for C/C++ functions -----*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2022 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_PRINTASCLANG_PRINTCLANGFUNCTION_H
#define SWIFT_PRINTASCLANG_PRINTCLANGFUNCTION_H

#include "swift/AST/Type.h"
#include "swift/Basic/LLVM.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"

namespace swift {

class FuncDecl;
class PrimitiveTypeMapping;

/// Responsible for printing a Swift function decl or type in C or C++ mode, to
/// be included in a Swift module's generated clang header.
class DeclAndTypeClangFunctionPrinter {
public:
  DeclAndTypeClangFunctionPrinter(raw_ostream &os,
                                  PrimitiveTypeMapping &typeMapping)
      : os(os), typeMapping(typeMapping) {}

  /// Print the C function declaration that corresponds to the given function
  /// declaration.
  void printFunctionDeclAsCFunctionDecl(FuncDecl *FD, StringRef name,
                                        Type resultTy);

private:
  raw_ostream &os;
  PrimitiveTypeMapping &typeMapping;
};

} // end namespace swift

#endif