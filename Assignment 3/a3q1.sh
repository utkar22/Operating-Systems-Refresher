read -p "Enter date (DD MM YYYY): "
{
	cal $REPLY
}||{
	echo "Invalid input"
}