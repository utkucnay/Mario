REQUIRED_PKG="make"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG|grep "install ok installed")
echo Checking $REQUIRED_PKG...
if [ "" = "$PKG_OK" ]; then
  echo "Will start install $REQUIRED_PKG."
  sudo apt-get --yes install $REQUIRED_PKG
else
  echo "Have $REQUIRED_PKG"
fi

echo "Compiling..."
make
