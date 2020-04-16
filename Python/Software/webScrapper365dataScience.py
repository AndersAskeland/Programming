###############################################################
################### Basic webscrapper #########################
###################### First program ##########################
###############################################################

from selenium import webdriver ## To navigate webpages
from selenium.webdriver.common.action_chains import ActionChains
from bs4 import BeautifulSoup ## To parse HTML
import requests ## To store HTML
import os ## to make dirs
import time ## to have breaks


#######################################
############ Define ###################
#######################################
parent_dir = "*********"


#######################################
############ Login and setup ##########
#######################################
## Open webbrowser
browser = webdriver.Safari()
time.sleep(3)

## Login 
browser.get("*website*") # Website to scrape

userElem = browser.find_element_by_id("user_email")
userElem.send_keys("*********")

userPass = browser.find_element_by_id("user_password")
userPass.send_keys("*********")

userPass.submit()
time.sleep(5)

## Clicks into main course
element = browser.find_element_by_xpath('/html/body/div[1]/div/div/div[2]/div[1]/div/div[1]/a/div/div[2]')
element.click()
time.sleep(5)

## Finds all courses <- store them as "elements"
elements = browser.find_elements_by_class_name("enrolled-child-course")
print("There are a total of " + str(len(elements)) + " courses.")
time.sleep(1)


## Loop that stores all the different courses into a list
course = [len(elements)]
i = 0
j = 0
k = 0
p = 0

######################################################
############ First loop - all courses ################
######################################################
for i in range(23):
    print("\n\n\n\n################################################")
    print("########### Now in primary loop " + str(i) + " ##############")
    print("################################################")

    # Returns to baseline
    browser.get("*****")

    # Find next course (find HTML source)
    link = browser.find_elements_by_css_selector(f"body > div > div > div > div.row.course-list.list > div:nth-child({i+2}) > div > div.row > a")
    enterLink = link[0].get_attribute("href")
                                                 
    # Enter course
    browser.get(enterLink)
    time.sleep(4)
    print("Now parsing course " + str(i)+ ".")

    # Create course diretory
    dirCourse = browser.find_element_by_css_selector("body > div.course-sidebar > h2").text
    extension1 = f"{i+1} - "
    time.sleep(1)
    path = os.path.join(parent_dir, extension1 + dirCourse)
    time.sleep(1) 
    os.mkdir(path)

    ## Enter first lecture
    browser.find_element_by_xpath("/html/body/div[2]/div[2]/div/ul/li[1]/a/div/span[2]").click()
    time.sleep(5)

    ## Find amount of lectures
    lecturesNr = browser.find_elements_by_css_selector("div > span.lecture-name")
    print("Amount of lectures inside " + dirCourse + " is " + str(len(lecturesNr)) + ".")
    i = 0
    j = 0
    k = 0
    
######################################################
############ Second loop - all lectures ##############
######################################################    
    for j in range(len(lecturesNr)):#lecture_heading
        print("\n\n\n\n########## Now in secondary loop " + str(j) + " for course: " + dirCourse + " ##############")
        print("###############################################################################################")

        # Creates a new directory for lecture
        dirLecture = browser.find_element_by_css_selector("#lecture_heading").text.strip()
        extension2 = f"{j+1} - "
        path = os.path.join(parent_dir, extension1 + dirCourse, extension2 + dirLecture)
        os.mkdir(path)
        os.chdir(path)
        print("New path is: " + path)

        # Saves potential text to text file 
        print("\n### Text ###")
        time.sleep(0.5)
        try:
            browser.find_element_by_css_selector("div.lecture-text-container").text
            text = browser.find_element_by_css_selector("div.lecture-text-container").text
            f = open(f"{dirLecture}.txt", "x")
            f.write(text)
            f.close()
            print("Text file saved.")        
        except:
            print("No text to save")

        # Download files
        print("\n### Download files ###")
        time.sleep(0.5)
        try:
            downloads = browser.find_elements_by_class_name("lecture-attachment-type-file [href]")
            downloadLink = [len(downloads)]
            for k in range(len(downloads)):
                downloadLink.insert(k, downloads[k].get_attribute("href"))
                myfile = requests.get(downloadLink[k])
                ext = downloadLink[k].split("_",1)[1]
                open(f"{dirLecture}.{ext}", 'wb').write(myfile.content)
            print("Saved a total of " + str(len(downloads)) + " files.")
        except:
            print("No files found")

        # Download files
        print("\n### Download PDFs ###")
        time.sleep(0.5)
        try:
            downloads = browser.find_elements_by_class_name("lecture-attachment-type-pdf_embed [href]")
            downloadLink = [len(downloads)]
            for k in range(len(downloads)):
                downloadLink.insert(k, downloads[k].get_attribute("href"))
                myfile = requests.get(downloadLink[k])
                ext = downloadLink[k].split("_",1)[1]
                open(f"{dirLecture}.{ext}", 'wb').write(myfile.content)
            print("Saved a total of " + str(len(downloads)) + " pdfs.")
        except:
            print("No PDF's found")

    
        # Download video urls
        print("\n### Video urls ###")
        time.sleep(0.5)
        try:
            htmlSource = browser.page_source
            soup = BeautifulSoup(browser.page_source, "html.parser")
            tags = soup.find(class_="wistia_video_foam_dummy").get("data-source-container-id")
            videoID = tags[7:]
            f = open(f"{path}/{dirLecture}.url", "x")
            f.write(f"[InternetShortcut]\nURL=https://fast.wistia.net/embed/iframe/{videoID}\nIconIndex=0")
            f.close()
            print("Video url was downloaded.")
        except:
            print("No video url found.")
        


        # Goes to next lecture
        print("Finished parsing lecture " + dirLecture + ".")
        browser.find_element_by_css_selector("#lecture_complete_button > span").click()
        time.sleep(3)

