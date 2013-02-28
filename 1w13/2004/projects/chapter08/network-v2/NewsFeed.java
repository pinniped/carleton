import java.util.ArrayList;

/**
 * The NewsFeed class stores news posts for the news feed in a
 * social network application (like FaceBook or Google+).
 * 
 * Display of the posts is currently simulated by printing the
 * details to the terminal. (Later, this should display in a browser.)
 * 
 * This version does not save the data to disk, and it does not
 * provide any search or ordering functions.
 * 
 * @author Michael Kölling and David J. Barnes
 * @version 0.2
 */
public class NewsFeed
{
	public static void main (String[] args) {
		NewsFeed newsfeed = new NewsFeed();

		for (int i = 1; i<=5; i++) {
			newsfeed.addPost(new MessagePost("Link", "This is post no." + i));
			newsfeed.addPost(new PhotoPost("Zelda", "file"+i, "This is picture no." +i));
			newsfeed.addPost(new EventPost("Ganon", "type" +i));
		}

		newsfeed.getFirstPost().addComment("This is a great post, man!");
		newsfeed.getFirstPost().like();
		newsfeed.getFirstPost().like();
		newsfeed.getFirstPost().unlike();

		newsfeed.show();
	}

    private ArrayList<Post> posts;

    /**
     * Construct an empty news feed.
     */
    public NewsFeed()
    {
        posts = new ArrayList<Post>();
    }

    /**
     * Add a post to the news feed.
     * 
     * @param post  The post to be added.
     */
    public void addPost(Post post)
    {
        posts.add(post);
    }

    /**
     * Show the news feed. Currently: print the news feed details
     * to the terminal. (To do: replace this later with display
     * in web browser.)
     */
    public void show()
    {
        // display all posts
        for(Post post : posts) {
            post.display();
            System.out.println();   // empty line between posts
        }
    }

	public Post getFirstPost() {
		return posts.get(0);
	}
}
