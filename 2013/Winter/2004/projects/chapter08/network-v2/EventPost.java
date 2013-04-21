public class EventPost extends Post {
    private String eventType;  

    /**
     * Constructor for objects of class MessagePost.
     * 
     * @param author    The username of the author of this post.
     * @param text      The text of this post.
     */
    public EventPost(String author, String eventType)
    {
        super(author);
        this.eventType = eventType;
    }

    /**
     * Return the text of this post.
     * 
     * @return The post's message text.
     */
    public String getEventType()
    {
        return eventType;
    }

	public String getContents() {
		return "This is a " +getEventType()+ " event!";
	}
}
