#!/bin/bash
set -e

echo "Regenerating Doxygen documentation..."
doxygen Doxyfile

echo "Regenerating Sphinx documentation..."
sphinx-build -b html docs/sphinx docs/sphinx/_build/html

echo "Documentation regenerated successfully."
