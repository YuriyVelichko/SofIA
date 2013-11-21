DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"


# -------------------------------------------
cd "$DIR/../../libs/mac"


# -------------------------------------------
if [ -e qt ] ; then
rm -R -f qt
fi	

# -------------------------------------------
echo UNCOMPRESS libssh2 
#

unzip "$DIR/../../archives/mac/QtCore.framework.zip"

# -------------------------------------------
cd "$DIR/../../libs/mac"

if [ -e __MACOSX ] ; then
rm -R -f __MACOSX
fi

